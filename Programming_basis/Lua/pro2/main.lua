require "members"
require "function"
require "player"
require "log"
require "item"
require "guns"

local tom= Player.new()

--print (tom.name, tom.life)
--[[tom.name = "Tom"
D.debug (tom.name, tom.life)

local doris=Player.new()
doris.name = "Doris"

D.debug(doris.name,doris.life)


for k,v in pairs(Guns) do
 --   print( v.name, v.attack)
    if(v.attack == 20) then
        tom.weapon=v
        break
    end
end
--]]
local gun=Gun.new()
local input=io.open("gun.txt", "rb")
--local data=input:read("*all")
while true do
    local data=input:read("*line")
   if data then
        --D.debug(data)
        --if tonumber(data) ==20 then
        if data == "Doland" then
            gun.name=data
            data=input:read("*line")
            gun.demage=tonumber(data)
        end
    else
        break
    end
end
input:close()

D.debug(gun:getName(),gun:getType(),gun:getDemage())



--D.debug("tom's weapon is ", tom.weapon.name)
--print("Tome's Weapon is",tom.weapon.name)

--tom:Attack(doris)
--D.debug(doris.name,doris.life)
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
