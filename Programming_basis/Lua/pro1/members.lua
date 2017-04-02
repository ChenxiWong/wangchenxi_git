members={Tom=10, Jack=9, Doris=11, John=10}
local Tom={weapon="none", amor="leather"}




--[[


for k, v in pairs(members) do
    if(v == 10) then
        print(k, "is 10 years old.")
    elseif(v == 9) then
        print(k, "is 9 years old.")
    else
        print(k, "is 11 years old.")
    end
    print( k, v)
end

membersi={"Tom", "Jack", "Doris"}

for k, v in pairs(membersi) do
    print( k, v)
end

--]]
