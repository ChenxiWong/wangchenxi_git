Item={name="unkown",type="unkown"}
Item.__index=Item

function Item:getType()
    return self.type
end

function Item:getName()
    return self.name
end
