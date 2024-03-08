#include <iostream>
#include <bitset>
#include <map>
#include <stdexcept>
#include <random>

// Section i


template<size_t N>
int population_count(const std::bitset<N>& bits_set) {
    int count = 0;
    for (size_t i = 0; i < N; i++) {
        if (bits_set[i]) {
            count++;
        }
    }
    return count;
}

template <size_t N>
size_t count_trailing_zeros(const std::bitset<N>& bits_set) {
    size_t count = 0;
    for (size_t i = 0; i < N; ++i) {
        if (!bits_set[i]) {
            ++count;
        } else {
            break;
        }
    }
    return count;
}


// Section ii 


template<size_t N>
int popcount_Noloop(const std::bitset<N>& bits_set) {
    if constexpr (N <= 64) {
        return std::bitset<N>(bits_set.to_ullong()).count();
    } else {
        constexpr size_t M = N - 64;
        return popcount_Noloop(std::bitset<64>(bits_set.to_ullong())) + popcount_Noloop(bits_set >> 64);
    }
}
template<size_t N>
int countr_zero_Noloop(const std::bitset<N>& bits_set) {
    if constexpr (N <= 64) {
        return std::bitset<N>(bits_set.to_ullong()).count() - 1;
    } else {
        constexpr size_t M = N - 64;
        if (bits_set.to_ullong() == 0) {
            return 64 + count_trailing_zeros(bits_set >> 64);
        } else {
            return count_trailing_zeros(std::bitset<64>(bits_set.to_ullong()));
        }
    }
}



// Section iv 



template <size_t N>
struct BitsetComparatorNoLoop {
    bool operator()(const std::bitset<N>& lhs, const std::bitset<N>& rhs) const {
        try {
            return lhs.to_ullong() < rhs.to_ullong();
        } catch (const std::overflow_error& e) {
            std::cerr << "Bitset too large for comparison using to_ullong(): " << e.what() << '\n';
            return false;
        }
    }
};

template <size_t N>
struct BitsetComparator {
    bool operator()(const std::bitset<N>& lhs, const std::bitset<N>& rhs) const {
        for (size_t i = N; i > 0; --i) {
            if (lhs[i - 1] != rhs[i - 1]) { // Use != to check for difference
                return lhs[i - 1] < rhs[i - 1]; // Correctly compare the bit values
            }
        }
        return false; // If all bits are the same, then lhs is not less than rhs
    }
};


// with loop
template <size_t N>
void store_and_sort_bitsets_WoLoops(std::optional<unsigned int> seedOpt = std::nullopt) {
    std::random_device rd;
    std::mt19937 gen = seedOpt.has_value() ? std::mt19937(seedOpt.value()) : std::mt19937(rd());

    std::map<std::bitset<N>, int, BitsetComparatorNoLoop<N>> sorted_bitsets;
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 10; ++i) {
        std::bitset<N> bs;
        for (size_t j = 0; j < N; ++j) {
            bs[j] = dis(gen);
        }
        sorted_bitsets[bs] = i;
    }

    for (const auto& pair : sorted_bitsets) {
        std::cout << "Bitset: " << pair.first << ", Decimal: " << pair.first.to_ullong()  << std::endl;
    }
}

template <size_t N>
void store_and_sort_bitsets_loops(std::optional<unsigned int> seedOpt = std::nullopt) {
    std::random_device rd;
    std::mt19937 gen = seedOpt.has_value() ? std::mt19937(seedOpt.value()) : std::mt19937(rd());

    std::map<std::bitset<N>, int, BitsetComparator<N>> sorted_bitsets;
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 10; ++i) {
        std::bitset<N> bs;
        for (size_t j = 0; j < N; ++j) {
            bs[j] = dis(gen);
        }
        sorted_bitsets[bs] = i;
    }

    for (const auto& pair : sorted_bitsets) {
        std::cout << "Bitset: " << pair.first << ", Decimal: " << pair.first.to_ullong() << std::endl;
    }
}
// Section v
template<size_t N>
int count_occupied_orbitals_optimized(const std::bitset<N>& bs, size_t start, size_t end) {
    if (end <= start || end > N) return 0; // Ensure valid range

    // We're using bit manipulation on unsigned long long before converting to bitset
    std::bitset<N> startMask = start > 0 ? std::bitset<N>((1ULL << start) - 1) : std::bitset<N>(0);
    std::bitset<N> endMask = end < N ? std::bitset<N>((1ULL << end) - 1) : std::bitset<N>(-1ULL); // Using -1ULL to set all bits

    std::bitset<N> rangeMask = endMask ^ startMask;
    return (bs & rangeMask).count();
}



int main() {
    // Bit declaration
    // Section i
   std::bitset<64> bs(0b00011100);
    std::cout << "Number of bits set: " << population_count(bs) << std::endl;
    std::cout << "Number of trailing zeros: " << count_trailing_zeros(bs) << std::endl;

    // Section ii
    std::cout << "Number of bits set: " << popcount_Noloop(bs) << std::endl;
    std::cout << "Number of trailing zeros: " << countr_zero_Noloop(bs) << std::endl;


    // Section iv

  unsigned int seed = 123456789;

    // Calling the function without loops and with a seed
    std::cout << "Sorted bitsets without loops (seeded):" << std::endl;
    store_and_sort_bitsets_WoLoops<64>(seed); // Replace 16 with your desired N
    std::cout << std::endl;

    // Calling the function with loops and with a seed
    std::cout << "Sorted bitsets with loops (seeded):" << std::endl;
    store_and_sort_bitsets_loops<64>(seed); // Replace 16 with your desired N
    std::cout << std::endl;

    // Example of calling the function without providing a seed 
    std::cout << "Sorted bitsets without loops: " << std::endl;
    store_and_sort_bitsets_WoLoops<64>(); // Replace 16 with your desired N
    std::cout << std::endl;

    // Example of calling the function with loops without providing a seed 
    std::cout << "Sorted bitsets with loops: " << std::endl;
    store_and_sort_bitsets_loops<64>(); // Replace 16 with your desired N


    // Section v

    std::cout << "Number of occupied orbitals: " << count_occupied_orbitals_optimized(bs, 2, 6) << std::endl;
   



    return 0;
}



