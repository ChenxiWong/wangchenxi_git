Gun={demage=0}
Gun.__index=Gun
setmetatable(Gun, Item)

function Gun.new()
    local obj={}
    setmetatable(obj,Gun)
    obj.type="gun"
    obj.name="gun_name"
    return obj
end

function Gun:getDemage()
    return self.demage
end

