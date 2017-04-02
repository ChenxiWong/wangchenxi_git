require "members"
require "guns"
require "function"
require "player"


local tom= Player.new()

--print (tom.name, tom.life)
tom.name = "Tom"
print (tom.name, tom.life)

local doris=Player.new()
doris.name = "Doris"

print(doris.name,doris.life)


for k,v in pairs(Guns) do
 --   print( v.name, v.attack)
    if(v.attack == 20) then
        tom.weapon=v
        break
    end
end

print("Tome's Weapon is",tom.weapon.name)

tom:Attack(doris)
print(doris.name,doris.life)
--tom:Attack(doris)


--Guns.Attack(tom.weapon, doris)
--print(doris.name,doris.life)

--print(Math.add(1,1))



--[[
print(Tom.weapon)

x = 10
function foo()
    local x=100
end

foo()

print(x)
--]]
