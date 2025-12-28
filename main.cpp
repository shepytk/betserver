#include <vix/core.h>
#include <iostream>

using namespace vix;
namespace J = vix::json;

int main() {
    App app;
    
    // Simple health check endpoint
    app.get("/", [](auto &, auto &res) {
        res.json({"message", "Betserver is running", "status", "ok"});
    });
    
    // Get all bets endpoint
    app.get("/api/bets", [](auto &, auto &res) {
        using namespace J;
        res.json({
            "bets", array({}),
            "count", 0
        });
    });
    
    // Create a new bet
    app.post("/api/bets", [](Request &req, Response &res) {
        const auto &body = req.json();
        res.status(201).json({
            "message", "Bet created successfully",
            "bet", body
        });
    });
    
    // Get bet by ID
    app.get("/api/bets/{id}", [](Request &req, Response &res) {
        auto id = req.param("id");
        res.json({
            "id", id,
            "message", "Bet details"
        });
    });
    
    // Update bet
    app.put("/api/bets/{id}", [](Request &req, Response &res) {
        auto id = req.param("id");
        const auto &body = req.json();
        res.json({
            "message", "Bet updated successfully",
            "id", id,
            "bet", body
        });
    });
    
    // Delete bet
    app.del("/api/bets/{id}", [](Request &req, Response &res) {
        auto id = req.param("id");
        res.json({
            "message", "Bet deleted successfully",
            "id", id
        });
    });
    
    std::cout << "Betserver starting on port 8080..." << std::endl;
    app.run(8080);
    
    return 0;
}
