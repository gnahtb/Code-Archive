const fi='';
      fo='';
var s:string;
    a:array[1..100] of string;
    i,j,rslt:longint;
    c:boolean;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(s);
        rslt:=1;
        a[1]:=s;
        for i:=1 to 49 do
                begin
                        s:=s[length(s)]+s;
                        delete(s,length(s),1);
                        c:=false;
                        for j:=1 to rslt do
                                if a[j]=s then
                                        begin
                                                c:=true;
                                                break;
                                        end;
                        if not c then
                                begin
                                        inc(rslt);
                                        a[rslt]:=s;
                                end;
                end;
        write(rslt);
        close(input);
        close(output);
end.
