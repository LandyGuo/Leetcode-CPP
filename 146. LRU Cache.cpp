/*
146. LRU Cache 
Difficulty: Hard
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
//思路：
/*
用一个list,get或set时，hit就将元素移到链表头部,为了快速查找,map存key,list存value
当新增元素超过容量限制时，就删除该链表最后一个元素，并从map中删除:注意这里有从list元素回到map对应关系，所以list里面还应该放key
综上，为加快查找，用unordered_map存key；为了保持时序，用list,为了能从list元素定位map中的元素实现同步删除，list元素类型为pair<key,value>
注意：get时也要更新元素位置
*/
class LRUCache{
private:
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> m;
	int capacity;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;//特别注意：这里必须要加this,在vs中可以不加
	}

	int get(int key) {
		if (m.find(key) == m.end())//没找到
			return -1;
		//找到，移到第一位
		int value = m[key]->second;
		l.erase(m[key]);//删除
		pair<int, int>p = { key, value };
		l.push_front(p);//在表头插入
		m[key] = l.begin();//更新索引位置
		return m[key]->second;
	}

	void set(int key, int value) {
		if (m.find(key) != m.end())//如果能找到，不用插入
		{
			//把当前key对应的节点移动到链表头部
			l.erase(m[key]);//删除
			l.push_front({ key, value });//在表头插入
			m[key] = l.begin();//更新索引位置
		}
		else//不能找到时，需要插入
		{
			//插入新的值
			l.push_front({ key, value });
			m[key] = l.begin();
			//容量判断，超过容量要删除
			if (m.size() > capacity)
			{
				int delete_key = l.back().first;
				l.pop_back();
				m.erase(delete_key);
			}
		}
	}
};
