uses math;
const fi='';
      fo='';
      lim=100;
type tlist=array[0..lim+5] of longint;
var r,a,p:tlist;
    n,w:longint;
    c:boolean;
procedure enter;
var i:longint;
begin
        //assign(input,fi);
        //reset(input);
        readln(n,w);
        for i:=1 to n do
                begin
                        read(a[i]);
                        p[i]:=i;
                end;
        //close(input);
end;
procedure swap(var x,y:longint);
var t:longint;
begin
        t:=x;
        x:=y;
        y:=t;
end;
procedure sort(var x1,x2:tlist);
var i,j:longint;
begin
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if x1[i]>x1[j] then
                                begin
                                        swap(x1[i],x1[j]);
                                        swap(x2[i],x2[j]);
                                end;
end;
procedure solve;
var i,t:longint;
begin
        fillchar(r,sizeof(r),0);
        for i:=1 to n do
                begin
                        r[i]:=(a[i]+1) div 2;
                        w:=w-r[i];
                        if w<0 then
                                begin
                                        c:=false;
                                        exit;
                                end;
                end;
        if w=0 then exit;
        for i:=n downto 1 do
                if w>0 then
                        begin
                                t:=min(w,a[i]-r[i]);
                                r[i]:=r[i]+t;
                                w:=w-t;
                        end
                else break;
end;
procedure print;
var i:longint;
begin
        //assign(output,fo);
        //rewrite(output);
        if not c then
                write(-1)
        else
                for i:=1 to n do write(r[i],#32);
        //close(output);
end;
begin
        enter;
        sort(a,p);
        c:=true;
        solve;
        sort(p,r);
        print;
end.
