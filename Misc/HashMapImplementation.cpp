// HashMap Implementation in C++
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll TABLE_SIZE = 1e+5;
template<typename K, typename V>
class HashNode
{
	public:
		HashNode* next;
		K key;
		V val;
		HashNode(K ke, V va)
		{
			key = ke;
			val = va;
			next = NULL;
		}
		~HashNode()
		{
			delete next;
		}
};
template<typename K>
class KeyHash
{
	public:
		ll operator[] (const K &key)
		{
			return key%TABLE_SIZE;
		}
};
template<typename K, typename V, typename F = KeyHash<K> >
class HashMap
{
	private:
		int* p =new int[5];
		HashNode<K,V>* nnd = new HashNode<K,V>();
		HashNode<K,V>* table[TABLE_SIZE];
		F hashFunc;
		V garbage;
	public:
		HashMap()
		{
			for(int i=0;i<TABLE_SIZE;++i)
			{
				table[i] = NULL;
			}
		}
		~HashMap()
		{
			for(int i=0;i<TABLE_SIZE;++i)
			{
				if(table[i]) delete table[i];
			}
		//	delete [] table;
		}
		void put(K key, V val)
		{
			ll hashVal = hashFunc[key];
			auto entry = table[hashVal];
			HashNode<K,V>* prev = NULL;
			bool ok = false;
			while(entry != NULL)
			{
				if(entry->key == key)
				{
					entry->val = val;
					ok = true;
					break;
				}
				prev = entry;
				entry = entry->next;
			}
			if(!ok)
			{
				HashNode<K,V>* nnode = new HashNode<K,V>(key,val);
				if(prev) prev->next = nnode;
				else table[hashVal] = nnode;
			}
		}
		V get(K key)
		{
			ll hashVal = hashFunc[key];
			auto entry = table[hashVal];
			
			while(entry!=NULL)
			{
				if(entry->key == key)
				{
					return entry->val;
				}
				entry = entry->next;
			}
			return garbage;
		}
};
class StringHash
{
	private:
		ll MOD = TABLE_SIZE;
		inline ll mod(ll x)
		{
			return x%MOD;
		}
	public:
	ll operator[] (const string &s)
	{
		ll val = 0;
		ll prime = 1e+9;
		prime+=7;
		ll p = 1;
		for(ll i=0;i<s.size();++i)
		{
			val = mod(mod(val) + mod(s[i])*mod(p));
			p = mod(p*prime);
		}
		return val;
	}
	
};
int main()
{
	HashMap<ll, ll> mp;
	mp.put(1,105);
	mp.put(2,106);
	mp.put(3,107);
	cout<<mp.get(1)<<endl;
	cout<<mp.get(2)<<endl;
	cout<<mp.get(3)<<endl;
	ll kk = 1e+5;
	kk+=1;
	mp.put(kk,55);
	cout<<mp.get(1)<<endl;
	cout<<mp.get(kk)<<endl;
	
	
	HashMap<string, ll, StringHash> mp2;
	mp2.put("Banipreet", 1);
	mp2.put("Banipreet", 15);
	cout<<mp2.get("Banipreet")<<endl;
	
	mp2.put("Hello",2);
	cout<<mp2.get("Hello")<<endl;
	
}

