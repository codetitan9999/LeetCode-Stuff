class Logger {
public:
    unordered_map<string , int> mp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!mp.count(message)) {
            mp[message] = timestamp;
            return true;
        }


        if(mp[message] +10  <= timestamp) {
            mp[message] = timestamp;
            return true;
        }

        return false;
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */