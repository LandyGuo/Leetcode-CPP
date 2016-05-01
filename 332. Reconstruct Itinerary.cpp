/*
332. Reconstruct Itinerary  
Difficulty: Medium
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/
//2nd pass
/*
1.增加访问标识符,标识某个地点已经去过
2.用回溯法确定第一个能访问完所有目的地的路径，然后返回即可
*/

struct to_place
{
    string name;
    bool has_been;
    to_place(string name):name(name),has_been(false){};
    bool operator<(to_place const & other) const{
        return name<other.name;}
};

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		map<string, vector<to_place>> from_to_map;
		for (pair<string, string> ticket : tickets)
			from_to_map[ticket.first].push_back(to_place(ticket.second));
		for (auto &s : from_to_map)//路程进行排序
			sort(s.second.begin(), s.second.end());
		vector<string> path;
		path.push_back("JFK");
		int total_places = tickets.size();
		if (dfs("JFK", total_places, from_to_map, path))	
			return path;
		return path;
	}

	bool dfs(string cur, int total_places, map<string, vector<to_place>>&from_to_map, vector<string>&path)
	{
		if (total_places == 0)
			return true;
		for (to_place& choice : from_to_map[cur])
		{
			if (choice.has_been == true)
				continue;
			path.push_back(choice.name);
			choice.has_been = true;
			if (dfs(choice.name, total_places-1, from_to_map, path))
				return true;
			choice.has_been = false;
			path.pop_back();
		}
		return false;
	}
};
