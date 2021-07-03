var MyCalendar = function() {
    this.segs = [];
};

MyCalendar.prototype.book = function(start, end) {
    for (let i = 0; i < this.segs.length; ++i) {
        if (Math.max(this.segs[i].start, start) <= Math.min(this.segs[i].end, end - 1)) {
            return false;
        }
    }
    this.segs.push({'start': start, 'end': end - 1});
    return true;
};