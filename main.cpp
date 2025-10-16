#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Transaction {
    std::string date;
    std::string category;
    double amount;
};

class BudgetManager {
public:
    void addTransaction(const std::string& date, const std::string& category, double amount) {
        transactions.push_back({ date, category, amount });
    }

    double getTotalExpenses() const {
        double total = 0;
        for (const auto& t : transactions) {
            total += t.amount;
        }
        return total;
    }

    void printReport() const {
        std::cout << "\n=== Quicken Demo Budget Report ===\n";
        std::cout << std::left << std::setw(12) << "Date"
                  << std::setw(20) << "Category"
                  << std::setw(10) << "Amount\n";
        std::cout << "----------------------------------------\n";

        for (const auto& t : transactions) {
            std::cout << std::left << std::setw(12) << t.date
                      << std::setw(20) << t.category
                      << "$" << std::fixed << std::setprecision(2) << t.amount << "\n";
        }

        std::cout << "----------------------------------------\n";
        std::cout << "Total expenses: $" << getTotalExpenses() << "\n";
    }

private:
    std::vector<Transaction> transactions;
};

int main() {
    BudgetManager quickenDemo;

    quickenDemo.addTransaction("2025-10-17", "Groceries", 84.29);
    quickenDemo.addTransaction("2025-10-18", "Electric Bill", 62.40);
    quickenDemo.addTransaction("2025-10-18", "Netflix", 15.99);

    quickenDemo.printReport();

    return 0;
}
