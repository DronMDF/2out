# На примере денег

## Часть шестая

Последний шаг, конвертация валют.
Пишем тест...

```c++
make_shared<EqualTest>(
	make_shared<MoneyText>(
		make_shared<OrderMoney>(
			"USD",
			make_shared<Bank>("CHF", "USD", 2),
			make_shared<RealMoney>(5, "USD"),
			make_shared<RealMoney>(10, "CHF")
		)
	),
	"10 USD"
)
```

Сперва мы создадим очень простой банк (фиксированный банк для одной валюты)
```c++
class Bank final {
	Bank(const std::string &source, const std::string &to, int rate);
	int getRate(const std::string &source, const std::string &to) const;
}
```

Cовершенно очевидно, что конвертированные деньги должны реализовываться через декоратор.

Сперва показалось, что мне придется через шаблоны транслировать передаваемые монеты по отдельности.
И я уже начал писать вспомогатеотный класс, чтобы данные деньги отличались от тех денег, которые уже умеет принимать OrderMoney.
Но тут я вовремя вспомнил о том, что шаблоны с переменным числом аргументов умеют распаковываться в функции.

Добавляем новый конструктор в OrderMoney

```c++
template <typename ... T>
OrderMoney(
	const std::string &currency,
	const std::shared_ptr<const Bank> &bank,
	const T & ... money
) : OrderMoney(std::make_shared<ExchangedMoney>(money, bank, currency)...)
{
}
```

Осталось только создать объект ExchangedMoney.
```c++
ExchangedMoney::ExchangedMoney(
	const shared_ptr<const Money> &money,
	int rate,
	const string &currency
) : money(money), rate(rate), _currency(currency)
{
}

ExchangedMoney::ExchangedMoney(
	const shared_ptr<const Money> &money,
	const shared_ptr<const Bank> &bank,
	const string &currency
) : ExchangedMoney(money, bank->getRate(money->currency(), currency), currency)
{
}

int ExchangedMoney::amount() const
{
	return money->amount() / rate;
}

string ExchangedMoney::currency() const
{
	return _currency;
}
```

И это все изменения, которые необходимо произвести.
Запускаем тесты:
```
[==========] Running 6 tests
...
[ RUN      ] OrderMoney is unify all money over Bank
'10 USD' is equal '10 USD'
[       OK ] OrderMoney is unify all money over Bank (0 ms)
[----------] 6 test from  (0 ms total)
[==========] 6 tests ran.
[  PASSED  ] 6 test.
```

- [x] $5 + 10CHF = $10 если курс обмена 2:1
- [x] $5 * 2 = $10
- [ ] Money это data class
- [ ] Преобразование Money в текст для отчета
- [x] Общая сумма по всем позициям (простой случай)
- [x] Переименовать TimesMoney в OrderItemMoney со всеми вытекающими.
- [x] Заказ из одной позиции
- [x] Заказ из трех и более позиций
- [x] Обмен валют

[Продолжить](TUTORIAL7.ru.md)
