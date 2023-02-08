using DHT.Models;
using Microsoft.EntityFrameworkCore;

namespace DHT.Database
{
    public class DHTDataContext : DbContext
    {
        public DHTDataContext(DbContextOptions<DHTDataContext> options) : base(options) { }

        public DbSet<DHTData> DHTDatas { get; set; }
    }
}
