local GrayGun={attack=10, name="Cookie"}
local GreenGun={attack=20, name="Dolan"}
local BlueGun={attack=30, name="Arc"}
Guns={GrayGun, GreenGun, BlueGun}
function Guns.Attack(gun, who)
    who.life = who.life-gun.attack
end
