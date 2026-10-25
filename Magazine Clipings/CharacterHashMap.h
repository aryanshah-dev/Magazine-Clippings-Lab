
#ifndef CHARACTER_HASH_MAP_H
#define CHARACTER_HASH_MAP_H

#include <array>

class CharacterHashMap {
private:
    static const int CAPACITY = 512;

    std::array<char, CAPACITY> keys{};
    std::array<int, CAPACITY> values{};
    std::array<bool, CAPACITY> occupied{};

    int hash(char key) const {
        unsigned char character =
            static_cast<unsigned char>(key);
        return character % CAPACITY;
    }

    int findIndex(char key) const {
        int index = hash(key);

        for (int i = 0; i < CAPACITY; i++) {
            if (!occupied[index] || keys[index] == key) {
                return index;
            }

            index = (index + 1) % CAPACITY;
        }

        return -1;
    }

public:
    void increment(char key) {
        int index = findIndex(key);

        if (index == -1) {
            return;
        }

        if (!occupied[index]) {
            keys[index] = key;
            values[index] = 0;
            occupied[index] = true;
        }

        values[index]++;
    }

    int get(char key) const {
        int index = hash(key);

        for (int i = 0; i < CAPACITY; i++) {
            if (!occupied[index]) {
                return 0;
            }

            if (keys[index] == key) {
                return values[index];
            }

            index = (index + 1) % CAPACITY;
        }

        return 0;
    }

    bool use(char key) {
        int index = hash(key);

        for (int i = 0; i < CAPACITY; i++) {
            if (!occupied[index]) {
                return false;
            }

            if (keys[index] == key) {
                if (values[index] <= 0) {
                    return false;
                }

                values[index]--;
                return true;
            }

            index = (index + 1) % CAPACITY;
        }

        return false;
    }
};

#endif
