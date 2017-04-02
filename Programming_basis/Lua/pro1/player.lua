Player={}

Player.__index=Player

function Player.new()
    local obj ={name="none", life=1000}
    setmetatable(obj,Player)
    return obj
end

function Player:Attack(target)
    --print(target.name)
    target.life = target.life - self.weapon.attack
end
