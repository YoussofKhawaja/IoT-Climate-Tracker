namespace DHT.Models
{
    public class DHTData
    {
        public Guid Id { get; set; }
        public float Temperature { get; set; }
        public float Humidity { get; set; }
        public DateTime Timestamp { get; set; }
        public String Location { get; set; }
    }
}
