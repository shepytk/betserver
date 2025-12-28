#include <vix/vix.hpp>
#include <iostream>

using namespace vix;

int main() {
    App app;
    
    // Simple health check endpoint
    app.get("/", [](const Request& req, Response& res) {
        res.json({{"message", "Betserver is running"}, {"status", "ok"}});
    });
    
    // Get all bets endpoint
    app.get("/api/bets", [](const Request& req, Response& res) {
        res.json({
            {"bets", json::array()},
            {"count", 0}
        });
    });
    
    // Create a new bet
    app.post("/api/bets", [](const Request& req, Response& res) {
        auto body = req.json();
        res.status(201).json({
            {"message", "Bet created successfully"},
            {"bet", body}
        });
    });
    
    // Get bet by ID
    app.get("/api/bets/:id", [](const Request& req, Response& res) {
        std::string id = req.params["id"];
        res.json({
            {"id", id},
            {"message", "Bet details"}
        });
    });
    
    // Update bet
    app.put("/api/bets/:id", [](const Request& req, Response& res) {
        std::string id = req.params["id"];
        auto body = req.json();
        res.json({
            {"message", "Bet updated successfully"},
            {"id", id},
            {"bet", body}
        });
    });
    
    // Delete bet
    app.del("/api/bets/:id", [](const Request& req, Response& res) {
        std::string id = req.params["id"];
        res.json({
            {"message", "Bet deleted successfully"},
            {"id", id}
        });
    });
    
    std::cout << "Betserver starting on port 8080..." << std::endl;
    app.listen(8080);
    
    return 0;
}
