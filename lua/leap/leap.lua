local leap_year = function(number)
    if number % 4 == 0 and (number % 400 == 0 or number % 100 ~= 0) then
        return true
    end
    return false
end

return leap_year
