const fi='inp.txt';
      fo='out.txt';
var s,r:string;
    i,t:longint;
begin
        //assign(input,fi); reset(input);
        //assign(output,fo); rewrite(output);
        readln(s);
        t:=0;
        r:='YES';
        if length(s)>=2 then
                begin
                        for i:=1 to length(s) div 2 do
                                if s[i]<>s[length(s)-i+1] then inc(t);
                        if t<>1 then r:='NO';
                        if (t=0) and (length(s) mod 2<>0) then r:='YES';
                end;
        write(r);
        //close(input);
        //close(output);
end.
