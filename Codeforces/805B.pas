const fi='';
      fo='';
var s:ansistring;
    i,n:longint;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(n);
        s:='aa';
        for i:=3 to n do
                begin
                        s:=s+'a';
                        if s[length(s)]=s[length(s)-2] then
                                begin
                                        delete(s,length(s),1);
                                        s:=s+'b';
                                end;
                end;
        if n<2 then delete(s,1,1);
        write(s);
        close(input);
        close(output);
end.

