#include "Contest.h"

enum TDirection
{
	RIGHT,
	DOWN,
	LEFT,
	UP
};

struct Command
{
	string type;
	int num_steps;
};

void Forward(PI & rPos, TDirection eDir)
{
	switch (eDir)
	{
	case RIGHT:
		rPos.first++;
		break;
	case DOWN:
		rPos.second++;
		break;
	case LEFT:
		rPos.first--;
		break;
	case UP:
		rPos.second--;
		break;
	default:
		break;
	}
}

void Turn(TDirection & rDir)
{
	switch (rDir)
	{
	case RIGHT:
		rDir = DOWN;
		break;
	case DOWN:
		rDir = LEFT;
		break;
	case LEFT:
		rDir = UP;
		break;
	case UP:
		rDir = RIGHT;
	default:
		break;
	}
}

struct Grid
{
	PI extents;

	vector<PI> visitedpoints;

	void Visit(PI & rPoint)
	{
		visitedpoints.push_back(rPoint);
	}
};

ofstream &operator <<(ofstream & output, const Grid & rGrid)
{
	for (auto & pos : rGrid.visitedpoints)
	{
		output << pos << endl;
	}

	return output;
}

struct Alien
{
	PI position = { 0, 0 };
	double speed = 0.0;
	double health = 0.0;

	PI current_tick_position = {0, 0};
	bool active = false;
	bool dead = false;

	int spawntick = 0;

	int id = 0;

	TDirection direction = RIGHT;

	vector<PI> path;

	vector<Command> vCommands;

	void Run(Grid & rGrid)
	{
		rGrid.Visit(position);

		for (auto & c : vCommands)
		{
			for (int i = 0; i < c.num_steps; ++i)
			{
				if (c.type.compare("F") == 0)
				{
					Forward(position, direction);
					rGrid.Visit(position);
				}
				else if (c.type.compare("T") == 0)
				{
					Turn(direction);
				}
			}
		}

		path = rGrid.visitedpoints;
	}
};

ofstream &operator <<(ofstream & output, const Alien & rStruct)
{
	output << rStruct.position;

	return output;
}

ifstream &operator >> (ifstream & input, Alien & rA)
{

	return input;
}

struct Query
{
	int tick;
	int alienid;
};

enum TTowerState
{
	LOCKED,
	SEEKING
};

struct Tower
{
	double damage;
	int range;

	int cost = 0;

	int spawntick = 0;

	vector<PI> reached_alien_positions;

	TTowerState state = SEEKING;

	int locked_alien_id = -1;

	PI position;

	bool IsInRange(Alien & a)
	{
		return a.active && !a.dead && GetDistanceToAlien(a) <= range;
	}
	bool IsInRange(PI & p)
	{
		return GetDistanceToPoint(p) <= range;
	}

	double GetDistanceToPoint(PI & p)
	{
		return sqrt(pow(position.first - p.first, 2) + pow(position.second - p.second, 2));
	}

	double GetDistanceToAlien(Alien & a)
	{
		return sqrt(pow(position.first - a.current_tick_position.first, 2) + pow(position.second - a.current_tick_position.second, 2));
	}
};

/***********************************************************************************
************************************************************************************/
void	Contest::Run(std::ifstream & input, std::ofstream & output)
{
	Grid grid;
	input >> grid.extents;

	PI position;
	input >> position;

	char next;
	while (input.get(next))
	{
		if (next == '\n')
		{
			break;
		}
	}

	vector<Command> vCommands;

	string sCommandLine;
	std::getline(input, sCommandLine);

	stringstream ssCL(sCommandLine);

	while (!ssCL.eof())
	{
		Command c;
		ssCL >> c.type;
		ssCL >> c.num_steps;

		vCommands.push_back(c);
	}

	double health = 0.0;
	input >> health;

	double speed = 0.0;
	input >> speed;

	int num_aliens = 0;
	input >> num_aliens;

	vector<Alien> vAliens;

	for (int i = 0; i < num_aliens; ++i)
	{
		Alien alien;
		alien.position.first = position.first;
		alien.position.second = position.second;
		alien.speed = speed;
		alien.id = i;
		alien.health = health;
		alien.current_tick_position = position;

		alien.vCommands = vCommands;

		Grid tempgrid = grid;
		alien.Run(tempgrid);

		input >> alien.spawntick;

		vAliens.push_back(alien);
	}

	double towerdamage = 0.0;
	input >> towerdamage;

	int towerrange = 0;
	input >> towerrange;

	int towercost = 0;
	input >> towercost;

	int max_num_towers = 500;

	int gold = 0;
	input >> gold;

	vector<Tower> vTowers;

	int current_simulation_ticks = 0;
	string result;

	vector<PI> alien_path = vAliens[0].path;

	set<PI> occupied_positions;
	occupied_positions.insert(alien_path.begin(), alien_path.end());

	set<PI> available_positions;
	for (int x = 0; x < grid.extents.first; ++x)
	{
		for (int y = 0; y < grid.extents.second; ++y)
		{
			PI point = { x, y };
			if (occupied_positions.find(point) == occupied_positions.end())
			{
				available_positions.insert(point);
			}
		}
	}

	vector<pair<int, Tower>> all_possible_towers;
	
	for (auto & ap : available_positions)
	{
		Tower t;
		t.position = ap;
		t.cost = towercost;
		t.damage = towerdamage;
		t.range = towerrange;

		for (auto & pos : alien_path)
		{
			if (t.IsInRange(pos))
				t.reached_alien_positions.push_back(pos);
		}

		if(t.reached_alien_positions.empty() == false)
			all_possible_towers.push_back({ (int)t.reached_alien_positions.size(), t });
	}

	sort(all_possible_towers.begin(), all_possible_towers.end(), [](auto & a, auto & b) -> bool { return a.first > b.first; });

	while (gold >= towercost && vTowers.size() < max_num_towers && all_possible_towers.empty() == false)
	{
		// choose the best position
		

		/*vector<Tower> possible_towers;
		for (auto & ap : available_positions)
		{
			Tower t;
			t.position = ap;
			t.cost = towercost;
			t.damage = towerdamage;
			t.range = towerrange;

			for (auto & pos : alien_path)
			{
				if (t.IsInRange(pos))
					t.reached_alien_positions.push_back(pos);
			}

			if ((int)t.reached_alien_positions.size() > best_num_reached)
			{
				possible_towers.clear();
				besttower = t;
				possible_towers.push_back(t);
				best_num_reached = (int)t.reached_alien_positions.size();
			}
			else if ((int)t.reached_alien_positions.size() == best_num_reached)
			{
				possible_towers.push_back(t);
			}
		}*/

		auto iter = all_possible_towers.begin();

		Tower besttower = iter->second;
		auto besttoweriter = iter;

		if (!vTowers.empty())
		{
			int max_non_overlapping_points = MININT;

			for (; (iter != all_possible_towers.end()); ++iter)
			{
				int t_overlaps = 0;
				for (auto & t_reachable : iter->second.reached_alien_positions)
				{
					for (auto & tother : vTowers)
					{
						auto iter = std::find(tother.reached_alien_positions.begin(), tother.reached_alien_positions.end(), t_reachable);
						if (iter != tother.reached_alien_positions.end())
						{
							t_overlaps++;
							break;
						}
					}
				}

				int non_overlapping_points = (((int)iter->second.reached_alien_positions.size() - t_overlaps) + (int)iter->second.reached_alien_positions.size()) / 2;
				
				if (non_overlapping_points > max_non_overlapping_points)
				{
					max_non_overlapping_points = non_overlapping_points;
					besttower = iter->second;
					besttoweriter = iter;
				}
			}
		}

		vTowers.push_back(besttower);
		gold -= besttower.cost;

		all_possible_towers.erase(besttoweriter);
	}

	for (auto & t : vTowers)
	{
		output << t.position.first << " " << t.position.second << endl;
	}

	while (result.empty())
	{
		// check if any alien reached the end
		for (auto & a : vAliens)
		{
			if (a.active && !a.dead)
			{
				int index_for_tick = (current_simulation_ticks - a.spawntick) * a.speed;

				if (index_for_tick >= a.path.size())
				{
					output << current_simulation_ticks << endl;
					output << "LOSS" ;
					return;
				}
				else
				{
					a.current_tick_position = a.path[index_for_tick];
				}
			}
		}

		// spawn new aliens
		for (auto & a : vAliens)
		{
			if (current_simulation_ticks >= a.spawntick)
			{
				a.active = true;
			}
		}

		// simulate tower shots
		for (auto & t : vTowers)
		{
			if (current_simulation_ticks > t.spawntick)
			{
				if (t.state == LOCKED)
				{
					Alien & a = vAliens[t.locked_alien_id];

					if (!t.IsInRange(a))
					{
						t.state = SEEKING;
						t.locked_alien_id = -1;
					}
				}

				if (t.state == SEEKING)
				{
					int chosen_alien_id = -1;
					double chosen_alien_id_dist = 0.0;

					for (auto & a : vAliens)
					{
						if (t.IsInRange(a))
						{
							double distance = t.GetDistanceToAlien(a);
							if (chosen_alien_id == -1)
							{
								chosen_alien_id = a.id;
								chosen_alien_id_dist = distance;
							}
							else if (distance < chosen_alien_id_dist)
							{
								chosen_alien_id = a.id;
								chosen_alien_id_dist = distance;
							}
							else if (distance == chosen_alien_id_dist && a.id < chosen_alien_id)
							{
								chosen_alien_id = a.id;
								chosen_alien_id_dist = distance;
							}
						}
					}

					if (chosen_alien_id != -1)
					{
						t.state = LOCKED;
						t.locked_alien_id = chosen_alien_id;
					}
				}

				if (t.state == LOCKED)
				{
					Alien & a = vAliens[t.locked_alien_id];
					a.health -= t.damage;
				}
			}
		}

		// check for dead aliens
		bool all_dead = true;
		for (auto & a : vAliens)
		{
			a.dead = a.health <= 0.0;

			if (!a.dead)
				all_dead = false;
		}

		if (all_dead)
		{
			output << current_simulation_ticks << endl;
			output << "WIN";
			return;
		}

		++current_simulation_ticks;
	}

	/*int num_queries = 0;
	input >> num_queries;

	vector<Query> vQueries;
	for(int i = 0; i < num_queries; ++i)
	{ 
		Query q;
		input >> q.tick;
		input >> q.alienid;
		vQueries.push_back(q);

		Alien & a = vAliens[q.alienid];

		int index_for_tick = (q.tick - a.spawntick) * a.speed;

		auto final_position = a.position;
		if(index_for_tick < a.path.size())
			final_position = a.path[index_for_tick];

		output << q.tick << " " << a.id << " " << final_position.first << " " << final_position.second << endl;
	}*/
}