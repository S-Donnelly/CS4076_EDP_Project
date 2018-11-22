template<typename K, typename V>
class dictionary: std::map<K, I>
{
public:
	dictionary() {};
	virtual ~dictionary(){};
	void add(K key, V value);
	void remove(K key);
	V get(K key)
	std::vector<K>	keys() const;
	std::vector<V>	values() const;
};

template <typename K, typename V>
void dictionary<K, V>::add (K key, V value) { 
   keys.push_back(key);
   values.push_back(value);   
}