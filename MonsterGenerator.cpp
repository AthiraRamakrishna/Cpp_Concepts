/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Monster
{
    
    public:
        enum class Type
            {
                DRAGON,
                GOBLIN,
                OGRE,
                ORC,
                SKELETON,
                TROLL,
                VAMPIRE,
                ZOMBIE,
                MAX_MONSTER
            };
        
    
    private:
        std::string m_name{};
        std::string m_roar{};
        int m_hitpoints{};
        Type m_type{};
    
    public:
        Monster(Type monsterType, const std::string& name, const std::string& roar, int hitpoints):
        m_type{monsterType},
        m_name{name},
        m_roar{roar},
        m_hitpoints{hitpoints}
        {
            
        }
    
    std::string getTypeString() const
    {
        switch(m_type)
        {
            case Type::DRAGON:
                return "DRAGON";
            case Type::SKELETON:
                return "SKELETON";
            case Type::GOBLIN:
                return "GOBLIN";
            case Type::ORC:
                return "ORC";
            case Type::OGRE:
                return "OGRE";
            case Type::TROLL:
                return "TROLL";
            case Type::VAMPIRE:
                return "VAMPIRE";
            case Type::ZOMBIE:
                return "ZOMBIE";
            default:
                return "???";
        }
    }
    
    void print()
    {
        std::cout<<m_name<<" the "<<getTypeString()<<" has "<<m_hitpoints<<" points and says "<<m_roar;
    }
        
};

//this class can be static as ideally we dont need more than one generator object
class MonsterGenerator
{
   public:
   static Monster generateMonster();
   static int getRandomNumber(int min, int max);
    
};

Monster MonsterGenerator::generateMonster()
{
    using number_dragon = std::array<const char*,6>;
    static constexpr number_dragon s_names{"Bones","Flesh", "Ligments", "Skull", "RBC"};
    static constexpr number_dragon s_sounds{"rattle","screach", "scream", "squeak", "caterwaul", "hum"};
    return Monster{static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::MAX_MONSTER))), s_names[getRandomNumber(0,s_names.size()-1)], s_sounds[getRandomNumber(0,s_sounds.size()-1)],getRandomNumber(0,100)};
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
	static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
}

int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();
	return 0;
}
