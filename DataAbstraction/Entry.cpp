template <class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry() : key(KeyType()), value(ValueType())
{
}

template <class KeyType, class ValueType>
Entry<KeyType, ValueType>::Entry(const KeyType& keyValue, const ValueType& newValue) : key(keyValue), value(newValue)
{
}

template <class KeyType, class ValueType>
ValueType Entry<KeyType, ValueType>::getValue() const
{
	return value;
}

template <class KeyType, class ValueType>
KeyType Entry<KeyType, ValueType>::getKey() const
{
	return key;
}

template <class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setValue(const ValueType& newValue)
{
	value = newValue;
}

template <class KeyType, class ValueType>
void Entry<KeyType, ValueType>::setKey(const KeyType& newKey)
{
	key = newKey;
}

template <class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator==(const Entry<KeyType, ValueType>& rightHandValue) const
{
	return (key == rightHandValue.key);
}
template <class KeyType, class ValueType>
bool Entry<KeyType, ValueType>::operator>(const Entry<KeyType, ValueType>& rightHandValue) const
{
	return (key > rightHandValue.key);
}
