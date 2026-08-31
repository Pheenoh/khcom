.syntax unified
	.align 2, 0
	.global func_080CE710
	.thumb
	.thumb_func
	.type func_080CE710, %function
func_080CE710: @ 080CE710
	push {r4, r5, lr}
	adds r4, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r0, #0x0C
	bl func_08005B64
	adds r0, r4, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080CE760
	adds r0, r4, #0x0
	adds r0, #0xB8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _080CE744
	cmp r0, #0x53
	ble _080CE754
	cmp r0, #0xAD
	beq _080CE740
	cmp r0, #0xD3
	beq _080CE748
	b _080CE754
_080CE740:
	movs r2, #0x02
	b _080CE74A
_080CE744:
	movs r2, #0x02
	b _080CE756
_080CE748:
	movs r2, #0x03
_080CE74A:
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _080CE762
_080CE754:
	movs r2, #0x03
_080CE756:
	adds r1, r4, #0x0
	adds r1, #0x24
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _080CE762
_080CE760:
	movs r2, #0x00
_080CE762:
	ldrh r0, [r4, #0x26]
	cmp r0, r2
	beq _080CE776
	strh r2, [r4, #0x26]
	adds r0, r4, #0x0
	adds r0, #0x0C
	adds r1, r2, #0x0
	adds r2, r5, #0x0
	bl AnimStart
_080CE776:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
