const fi='';
      fo='';
      lim=10000;
var v:array[0..lim+5] of longint;
    c:array[-(lim+5)..lim+5] of boolean;
    m,n,i,k:longint;
    t:boolean;
    rslt:string;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        rslt:='NO';
        readln(n,m);
        repeat
                fillchar(c,sizeof(c),false);
                read(k);
                for i:=1 to k do
                        begin
                                read(v[i]);
                                c[v[i]]:=true;
                        end;
                t:=true;
                for i:=1 to n do
                        if c[i] and c[-i] then
                                t:=false;
                if t then rslt:='YES';
                dec(m);
        until m=0;
        write(rslt);
        close(input);
        close(output);
end.
