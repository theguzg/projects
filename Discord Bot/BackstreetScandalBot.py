# BackStreetScandalBot.py
import os
import discord
import youtube_dl
import asyncio
import random

from dotenv import load_dotenv
from discord.ext import commands


load_dotenv()
TOKEN = 'ODI4MDc1MzAzOTUxMDA3NzU0.YGkTOQ.SFcB8Kp71tWE409EVpidcfNsz8Q'
GUILD = 'DARK SOULS ELITISTS'

bot = commands.Bot(command_prefix='!')
queue = []

### AICI INCEPE CE TINE DE YT ###
youtube_dl.utils.bug_reports_message = lambda: ''

ytdl_format_options = {
    'format': 'bestaudio/best',
    'restrictfilenames': True,
    'noplaylist': True,
    'nocheckcertificate': True,
    'ignoreerrors': False,
    'logtostderr': False,
    'quiet': True,
    'no_warnings': True,
    'default_search': 'auto',
    'source_address': '0.0.0.0' # bind to ipv4 since ipv6 addresses cause issues sometimes
}

ffmpeg_options = {
    'options': '-vn'
}

ytdl = youtube_dl.YoutubeDL(ytdl_format_options)

class YTDLSource(discord.PCMVolumeTransformer):
    def __init__(self, source, *, data, volume=0.5):
        super().__init__(source, volume)
        self.data = data
        self.title = data.get('title')
        self.url = ""
        

    @classmethod
    async def from_url(cls, url, *, loop=None, stream=False):
        loop = loop or asyncio.get_event_loop()
        data = await loop.run_in_executor(None, lambda: ytdl.extract_info(url, download=not stream))
        if 'entries' in data:
            # take first item from a playlist
            data = data['entries'][0]
        filename = data['title'] if stream else ytdl.prepare_filename(data)
        return filename
### AICI SE TERMINA CE TINE DE YT ###

### VERIFICA DACA E CONECTAT LA VOICE CHAT ###
def bot_is_connected(ctx):
    voice_client = discord.utils.get(ctx.bot.voice_clients, guild=ctx.guild)
    return voice_client and voice_client.is_connected()

### VERIFICA DACA RULEAZA VREO MELODIE ###
def bot_is_playing(ctx):
    voice_client = discord.utils.get(ctx.bot.voice_clients, guild=ctx.guild)
    return voice_client and voice_client.is_playing()

def url_process(url):
    processed_url = url.replace('_', ' ')
    processed_url = processed_url.replace('-', '')
    processed_url = processed_url[:len(processed_url) - 16]

    return processed_url


### SA PORNEASCA IN MORTII LUI ###
@bot.event
async def on_ready():
    guild = discord.utils.get(bot.guilds, name=GUILD)
    print(
        f'{bot.user.name} is connected to the following guild:\n'
        f'{guild.name}(id: {guild.id})'
    )

    #BOT STATUS
    await bot.change_presence(activity=discord.Activity(type=discord.ActivityType.watching, name='@CONNECTR cum vinde soul la bosi'))

### BASIC ON MEMBER JOIN ###
@bot.event
async def on_member_join(member):
    await member.channel.send(
        f'> Mnezeii ma-tii **{member.name}**, esti cam gorgonzolly!'
    )

### SHAME DE LA NEDELK ###
@bot.command(name='shame', help='Tre sa fie chiar gae sa vinzi soul la bosi.')
async def dark_souls(ctx):

    dark_souls_quotes = [
        'Drq de boland cum drq sa iti vinzi souls de la bosi',
        'cuaie chiar nu esti in stare sa te feresti de aia',
        (
            'Am auzit ca ti ai vandut souls de la bosi ca ultimu crestin\n'
            'Cretin'
        ),
        (
            'Daca esti vai de capu tau\n'
            'Drq de skeletor'
        ),
        (
            'Du te drq mai ai 3 souls din cati bosi ai facut\n'
            'Vai de curu tau'
        ),
        'Las goie ca poți sa i dai parry lu nk',
        'Creq fac un sl1 broken sword no hit run ca m am cam enervat',
        'Copile am 30 de ore doar pe invazii nu fi ratat ca ți fac roll catch pana plângi',
        'Am citit descrierile la toate itemele yeyeaa',
    ]

    response = random.choice(dark_souls_quotes)
    async with ctx.typing():
        await asyncio.sleep(0.5)
    
    await ctx.send("```{}```".format(response))

### NEDELK HOLY WORDS ###
@bot.command(name='holy_words', help='Esti cam homo manelis, capota face. Iti pute guritza a gorgonzolly ca ai branzotty la pulotty.')
async def holy_words(ctx):

    holy_quotes = [
        'Me doare n curuleanu',
        'True șantier',
        'True chad',
        'Va arat cum sa luați pălăria asta dak nu mai sunteți gay',
        'Strenght îs for the hardcore',
        'Creq ai covid',
        'Nush ce zici tu de noodle pack ca e bon',
        'N am dorit rău cuiva pe lol cum îl doresc lu țiganca',
        'CUAIE JOACA BRAND',
        'Ma umplu de branzotty la pulotty de la câte kkturi legate de prieteni da share branzotty',
        (
            'LA MULTI ANI GURA DE CANAL !!!!\n'
            'facura\'si si tu 15 insf\n'
            'si deschideti tel tea\'s in gura'
        ),
        (
            'alina\n'
            'https://www.youtube.com/watch?v=8nv6vchiwG8\n'
            'asta RUPE TOOOT\n'
            'TOOOOT !!!\n'
            'RUPE\n\n\n'
            'ALINA\n'
            'RUPEE\n'
            'ASCULTA'
        ),
        (
            'deci nu pot sa cred cat de genial sunt\n'
            'o sa ma fac detectiv\n'
            'detectez controlori\n'
            'si oameni falsi XDXD'
        ),
        (
            'AMBULANT\n'
            'AZI TRE SA IMI DAI BANII DACA VREI SA VII LA BALU MEU\n'
            'GUZAN BOU\n'
            'CA MAINE SA II DAU\n'
            'SI SA TE TREC PE LISTA\n'
            'AUROLACUS CONCRESCUTUS'
        ),
        'cf ba pizdex',
        'zi child ce rest pasti',
        (
            'hai ca esti gay\n'
            'lasama sa fac ceiut\n'
            '<:ANDROGINUL:522177769267003403>'
        ),
        (
            'guza bou cu spume\n'
            'bai homo manelis\n'
            'te\'as in gurita\n'
            'ne vedem maine dupa scl\n'
            'sa mai vb\n'
            'si sa iti vad fata de guzan bou\n'
            '=]\n'
            '!'
        ),
    ]

    response = random.choice(holy_quotes)
    async with ctx.typing():
        await asyncio.sleep(0.5)
    
    await ctx.send("```{}```".format(response))

### LEAVE DA VOICECHAT ###
@bot.command(name='leave', help='Sa iasa in mortii lui din voice.')
async def leave(ctx):

    voice_client = ctx.message.guild.voice_client
    if voice_client.is_connected():
        await voice_client.disconnect()

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send("> **AM IESIT DIN PIZDA MOTI**")
    else:

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send("> Nu-i **conectat** in morti lui, nu vezi.")

### BACKSTREET BOYS ###
@bot.command(name="backstreet", help="Sa simti fain.")
async def backstreet_boy(ctx):

    if not ctx.message.author.voice:
        async with ctx.typing():
            await asyncio.sleep(0.5)
        
        await ctx.send("> **{}** is not connected to a voice channel.".format(ctx.message.author.name))
        return
    else:
        channel = ctx.message.author.voice.channel
    await channel.connect()
    
    try :
        server = ctx.message.guild
        voice_client = server.voice_client

        async with ctx.typing():
            filename = await YTDLSource.from_url('https://www.youtube.com/watch?v=POq2AznJO1Q', loop=bot.loop)
            voice_client.play(discord.FFmpegPCMAudio(executable="ffmpeg.exe", source=filename))
        await ctx.send(file=discord.File('backstreet.gif'))
    except:
        await ctx.send("> Nu-i **conectat** in morti lui.")

    ### LEAVE AFTER INACTIVITY ###
    while voice_client.is_playing():
        await asyncio.sleep(1)
    else:
        await asyncio.sleep(15)
    while voice_client.is_playing() or not voice_client.is_connected():
        break 
    else:
        await ctx.send("> **GATA CU BACKSTREET GAYS**")
        await voice_client.disconnect()
    ### AICI SE TERMINA LEAVE AFTER INACTIVITY ### 

### BACKSTREET FOREVER ###
@bot.command(name="backstreet_forever", help="Sa simti fain. Forever.")
async def backstreet_forever(ctx):

    if not bot_is_connected(ctx):

        if not ctx.message.author.voice:

            async with ctx.typing():
                await asyncio.sleep(0.5)

            await ctx.send("> **{}** is not connected to a voice channel.".format(ctx.message.author.name))
            return
        else:
            channel = ctx.message.author.voice.channel
            #DA O SINGURA DATA GIF-UL
            async with ctx.typing():
                await ctx.send(file=discord.File('backstreet.gif'))
        await channel.connect()

    try :
        server = ctx.message.guild
        voice_client = server.voice_client

        filename = await YTDLSource.from_url('https://www.youtube.com/watch?v=POq2AznJO1Q', loop=bot.loop)
        voice_client.play(discord.FFmpegPCMAudio(executable="ffmpeg.exe", source=filename))

    except:
        await ctx.send("> Nu-i **conectat** in morti lui.")

    #LOOP TIME
    while voice_client.is_playing():
        await asyncio.sleep(1)
    else:
        if bot_is_connected(ctx):
            return await backstreet_forever(ctx)
        else:
            return

### BASIC MUSIC PLAYER ###
@bot.command(name="play", help="Sa simti fain orice vrea pl ta.")
async def play(ctx, *, url):

    global queue

    if not bot_is_connected(ctx):

        if not ctx.message.author.voice:

            async with ctx.typing():
                await asyncio.sleep(0.5)

            await ctx.send("> **{}** is not connected to a voice channel.".format(ctx.message.author.name))
            return
        else:
            channel = ctx.message.author.voice.channel
        await channel.connect()

    ### DACA DEJA MERGE O MELODIE, DOAR O BAGA IN QUEUE SI LA REVEDERE ###
    if bot_is_playing(ctx):
        song_title = await YTDLSource.from_url(url, loop=bot.loop)

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send("> **{}** - *added to the queue*.".format(url_process(song_title.title())))
        os.remove(song_title.title())

        queue.append(url)
        return
    
    ### DACA NU CANTA NIMIC, BAGA IN QUEUE, II DA PLAY, O STERGE + STERGE FISIERUL AFERENT DIN FOLDER ###
    if not bot_is_playing(ctx):

        queue.append(url)
        ### CAT TIMP MAI SUNT MELODII DIN QUEUE, LE CANTA, NU MAI SUNT, SE OPRESTE ###
        while queue:

            server = ctx.message.guild
            voice_client = server.voice_client

            filename = await YTDLSource.from_url(queue[0], loop=bot.loop)
            voice_client.play(discord.FFmpegPCMAudio(executable="ffmpeg.exe", source=filename))

            async with ctx.typing():
                await asyncio.sleep(0.5)

            await ctx.send("> **{}** - *is now playing*.".format(url_process(filename.title())))
            del queue[0]  

            while bot_is_playing(ctx):
                await asyncio.sleep(1)
            
            #STERGE DIN FOLDER
            os.remove(filename.title())
            
### SKIP COMMAND ###
@bot.command(name="skip", help="Simti fain mai departe.")
async def skip(ctx):

    if not ctx.message.author.voice:

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send("> **{}** is not connected to a voice channel.".format(ctx.message.author.name))
        return

    if not bot_is_connected(ctx):

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send("> The **bot** is not connected to any voice channels!`")
        return

    if not bot_is_playing(ctx):

        async with ctx.typing():
            await asyncio.sleep(0.5)

        await ctx.send('> The **bot** is not playing any music right now!`')
        return
    else:
        server = ctx.message.guild
        voice_client = server.voice_client

        voice_client.stop()

### HOODFACE COMMAND ###
@bot.command(name="hoodface", help="Ba fata de capota.")
async def hoodface_summon(ctx):

    if not ctx.message.author.voice:
        async with ctx.typing():
            await asyncio.sleep(0.5)
        
        await ctx.send("> **{}** is not connected to a voice channel.".format(ctx.message.author.name))
        return
    else:
        channel = ctx.message.author.voice.channel
    await channel.connect()
    
    try :
        server = ctx.message.guild
        voice_client = server.voice_client

        async with ctx.typing():
            # filename = await YTDLSource.from_url('https://www.youtube.com/watch?v=POq2AznJO1Q', loop=bot.loop)
            voice_client.play(discord.FFmpegPCMAudio('fata_de_capota.mp3'))
        await ctx.send(file=discord.File('hoodface.png'))
    except:
        await ctx.send("> Nu-i **conectat** in morti lui.")

    ### LEAVE AFTER INACTIVITY ###
    while voice_client.is_playing():
        await asyncio.sleep(1)
    else:
        await asyncio.sleep(5)
    while voice_client.is_playing() or not voice_client.is_connected():
        break 
    else:
        await ctx.send("> **NO MORE HOODFACE**")
        await voice_client.disconnect()
    ### AICI SE TERMINA LEAVE AFTER INACTIVITY ### 
            
### PORNESTE BOT-UL ###
bot.run(TOKEN)
