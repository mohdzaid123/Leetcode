class Solution {
public:
   

string destCity(std::vector<std::vector<std::string>>& paths) {
    unordered_set<std::string> outgoingCities;

    // Add all cities with outgoing paths to the set
    for (const auto& path : paths) {
        outgoingCities.insert(path[0]);
    }

    // Find the city without outgoing path
    for (const auto& path : paths) {
        if (outgoingCities.find(path[1]) == outgoingCities.end()) {
            return path[1];
        }
    }

    // It is guaranteed that there will always be a destination city,
    // so this line should never be reached.
    return ""; 
}
};