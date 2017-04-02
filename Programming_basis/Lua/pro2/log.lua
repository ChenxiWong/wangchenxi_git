D={}
local function writeMsgToFile(filePath, msg)
end

function D.debug(...)
    local argv = {...}
    local msg = "["..os.date("%x %X", os.time()).." debug] "
    for k,v in pairs(argv) do
        msg = msg..tostring(v).." "
    end
    if release then
        return
        --write msg to file
        --writeMsgToFile("log.txt", msg)
    else
        --print
        print(msg)
    end
end

function D.info(...)
    local argv = {...}
    local msg = "["..os.date("%x %X", os.time()).." info] "
    for k,v in pairs(argv) do
        msg = msg..tostring(v).." "
    end
    if release then
        --write msg to file
        writeMsgToFile("log.txt", msg)
    else
        --print
        print(msg)
    end
end
