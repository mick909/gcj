# Check created number is valid or not :-p

(1..gets.to_i).each { |t|
    n = gets.to_i
    nn = n*n
    snn = nn.to_s
    if snn != snn.reverse then
#        print "#{n} #{n*n} : Invalid\n"
    else
        print "#{n*n}\n"
    end
}