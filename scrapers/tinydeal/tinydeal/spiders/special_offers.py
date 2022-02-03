import scrapy


class SpecialOffersSpider(scrapy.Spider):
    name = 'special_offers'
    allowed_domains = ['carrefour.ro']
    start_urls = ['https://carrefour.ro/it-c/telefoane-tablete-gadget-uri']

    def parse(self, response):
        for product in response.xpath("//div[@class='products wrapper grid products-grid']/ol/li"):

            #data cleaning
            old_price_str = product.xpath("div/div/div[@class='product-info-price']/div[1]/div/span[@class='old-price']/span/span/span/text()").get()
            price_str = product.xpath(".//div/a/@data-price").get()

            price_str += " Lei"

            if old_price_str is not None:
                old_price_str = old_price_str.replace("\xa0", ' ')
            else:
                old_price_str = ''
            #end of data cleaning

            yield {
                'name': product.xpath(".//div/a/@data-name").get(),
                'brand': product.xpath(".//div/a/@data-brand").get(),
                'price': price_str,
                'old_price': old_price_str
            }

            next_page = response.xpath("//li[@class='item pages-item-next']/@data-target").get()
            if next_page:
                yield scrapy.Request(url=next_page, callback=self.parse)
