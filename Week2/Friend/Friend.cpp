#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MagicDoll {
private:
    string name;
    int hp;
    int attack;
    int defense;
    int energy;
    int energyMax;
    int powerTime;
    double multiAttack;
    double multiDefense;

public:
    MagicDoll(string n, int h, int a, int d, int eMax)
        : name(n), hp(h), attack(a), defense(d),
          energy(0), energyMax(eMax), powerTime(-1),
          multiAttack(1.0), multiDefense(1.0) {}

    void setPowerUp(double atkMul, double defMul, int duration) {
        multiAttack = atkMul;
        multiDefense = defMul;
        powerTime = duration;
    }

    bool isAlive() const {
        return hp > 0;
    }

    int getEnergy() const {
        return energy;
    }

    int getEnergyMax() const {
        return energyMax;
    }

    void increaseEnergy() {
        energy++;
    }

    void resetEnergy() {
        energy = 0;
    }

    int getAttackValue() const {
        if (energy >= energyMax) {
            return attack * 2;
        }
        return attack;
    }

    int getDamageAgainst(const MagicDoll& opponent) const {
        int baseAttack = getAttackValue();
        double attackMultiplier = (powerTime > 0) ? multiAttack : 1.0;
        double opponentDefenseMultiplier = (opponent.powerTime > 0) ? opponent.multiDefense : 1.0;
        int effectiveAtk = static_cast<int>(baseAttack * attackMultiplier);
        int effectiveDef = static_cast<int>(opponent.defense * opponentDefenseMultiplier);
        if (effectiveDef == 0) effectiveDef = 1;
        int dmg = (effectiveAtk * effectiveAtk) / effectiveDef;
        return dmg;
    }

    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
    }

    void decreasePowerTime() {
        if (powerTime > 0) {
            powerTime--;
        }
    }
};

int main() {
    int n;
    cin >> n;

    int mIndex;
    double mAtkMul, mDefMul;
    int mPowerTime;
    cin >> mIndex >> mAtkMul >> mDefMul >> mPowerTime;

    vector<MagicDoll> miena;
    for (int i = 0; i < n; ++i) {
        string name;
        int hp, atk, def, eMax;
        cin >> name >> hp >> atk >> def >> eMax;
        miena.emplace_back(name, hp, atk, def, eMax);
        if (i == mIndex) {
            miena.back().setPowerUp(mAtkMul, mDefMul, mPowerTime);
        } else {
            miena.back().setPowerUp(1.0, 1.0, -1);
        }
    }

    int lIndex;
    double lAtkMul, lDefMul;
    int lPowerTime;
    cin >> lIndex >> lAtkMul >> lDefMul >> lPowerTime;

    vector<MagicDoll> luna;
    for (int i = 0; i < n; ++i) {
        string name;
        int hp, atk, def, eMax;
        cin >> name >> hp >> atk >> def >> eMax;
        luna.emplace_back(name, hp, atk, def, eMax);
        if (i == lIndex) {
            luna.back().setPowerUp(lAtkMul, lDefMul, lPowerTime);
        } else {
            luna.back().setPowerUp(1.0, 1.0, -1);
        }
    }

    int mPos = 0;
    int lPos = 0;
    int rounds = 0;

    while (mPos < n && lPos < n) {
        rounds++;

        if (rounds % 2 == 1) {
            MagicDoll& attacker = miena[mPos];
            MagicDoll& defender = luna[lPos];

            if (attacker.getEnergy() >= attacker.getEnergyMax()) {
                attacker.resetEnergy();
            } else {
                attacker.increaseEnergy();
            }

            int damage = attacker.getDamageAgainst(defender);
            defender.takeDamage(damage);
            attacker.decreasePowerTime();

            if (!defender.isAlive()) lPos++;
        } else {
            MagicDoll& attacker = luna[lPos];
            MagicDoll& defender = miena[mPos];

            if (attacker.getEnergy() >= attacker.getEnergyMax()) {
                attacker.resetEnergy();
            } else {
                attacker.increaseEnergy();
            }

            int damage = attacker.getDamageAgainst(defender);
            defender.takeDamage(damage);
            attacker.decreasePowerTime();

            if (!defender.isAlive()) mPos++;
        }
    }

    int mLeft = n - mPos;
    int lLeft = n - lPos;

    if (lPos == n) {
        cout << "Miena is victorious with " << mLeft;
        cout << (mLeft == 1 ? " character left." : " characters left.") << "\n";
    } else {
        cout << "Luna is victorious with " << lLeft;
        cout << (lLeft == 1 ? " character left." : " characters left.") << "\n";
    }
    cout << "The battle took " << rounds;
    cout << (rounds == 1 ? " turn." : " turns.") << "\n";

    return 0;
}
