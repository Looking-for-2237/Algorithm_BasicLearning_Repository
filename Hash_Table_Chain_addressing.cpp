// chaining_hash_table.cpp
#include <iostream>
#include <vector>
#include <list>
#include <utility>    // std::pair
#include <functional> // std::hash
#include <string>

template <typename Key, typename Value>
class ChainingHashTable
{
public:
    using Pair = std::pair<Key, Value>;

    explicit ChainingHashTable(size_t bucket_count = 101)
        : buckets(bucket_count), bucket_count(bucket_count), size_(0)
    {
    }

    // Insert (update value if the key already exists)
    void insert(const Key &key, const Value &value)
    {
        auto &bucket = buckets[index_for(key)];
        for (auto &p : bucket)
        {
            if (p.first == key)
            { // Key exists, update
                p.second = value;
                return;
            }
        }
        // Key not found, insert at the front (could also insert at the end)
        bucket.emplace_front(key, value);
        ++size_;
    }

    // Find: if found return true and assign value to 'out'; otherwise return false
    bool find(const Key &key, Value &out) const
    {
        const auto &bucket = buckets[index_for(key)];
        for (const auto &p : bucket)
        {
            if (p.first == key)
            {
                out = p.second;
                return true;
            }
        }
        return false;
    }

    // Erase: return true if the key exists and is erased; false otherwise
    bool erase(const Key &key)
    {
        auto &bucket = buckets[index_for(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                --size_;
                return true;
            }
        }
        return false;
    }

    bool empty() const { return size_ == 0; } // Check if empty
    size_t size() const { return size_; }     // Number of stored elements

    // Print hash table content (for debugging)
    void debug_print() const
    {
        for (size_t i = 0; i < buckets.size(); ++i)
        {
            std::cout << "bucket[" << i << "]:";
            for (const auto &p : buckets[i])
            {
                std::cout << " (" << p.first << "->" << p.second << ")";
            }
            std::cout << '\n';
        }
    }

private:
    std::vector<std::list<Pair>> buckets;
    size_t bucket_count;
    size_t size_;

    size_t index_for(const Key &key) const
    {
        return hasher(key) % bucket_count;
    }

    std::hash<Key> hasher;
};

// Demonstration
int main()
{
    ChainingHashTable<int, std::string> ht(7); // 7 buckets (small example)
    ht.insert(1, "Alice");
    ht.insert(8, "Bob"); // 1 and 8 will collide (1 % 7 == 8 % 7)
    ht.insert(15, "Carol");
    ht.insert(2, "Dave");

    std::cout << "Hash table content:\n";
    ht.debug_print();

    std::string name;
    int k = 8;
    if (ht.find(k, name))
    {
        std::cout << "Found key = " << k << ", value = " << name << '\n';
    }
    else
    {
        std::cout << "Key = " << k << " not found\n";
    }

    // Update existing key
    ht.insert(8, "Bobby");
    if (ht.find(8, name))
        std::cout << "After update, key = 8 -> " << name << '\n';

    // Erase
    if (ht.erase(15))
        std::cout << "Erased key = 15 successfully\n";
    else
        std::cout << "Failed to erase key = 15\n";

    std::cout << "Hash table after erase:\n";
    ht.debug_print();

    return 0;
}
