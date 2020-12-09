uses math;
const fi='';
      fo='';
      lim=100;
var d,t1,s:longint;
    min1,max1,r:array[0..lim+5] of longint;
    str:string;
procedure enter;
var i,t2:longint;
begin
        readln(d,s);
        t1:=0;
        t2:=0;
        for i:=1 to d do
                begin
                        readln(min1[i],max1[i]);
                        t1:=t1+min1[i];
                        t2:=t2+max1[i];
                end;
        if (s>t2) or (s<t1) then str:='NO';
end;
procedure solve;
var i,tmp:longint;
begin
        for i:=1 to d do r[i]:=min1[i];
        s:=s-t1;
        i:=1;
        while s>0 do
                begin
                        tmp:=min(max1[i]-min1[i],s);
                        r[i]:=r[i]+tmp;
                        s:=s-tmp;
                        inc(i);
                end;
end;
procedure print;
var i:longint;
begin
        writeln(str);
        if str='YES' then for i:=1 to d do write(r[i],' ');
end;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        str:='YES';
        enter;
        if str='YES' then solve;
        print;
        close(input);
        close(output);
end.

