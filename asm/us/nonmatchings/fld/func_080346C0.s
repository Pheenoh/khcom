.syntax unified
	.align 2, 0
	.global func_080346C0
	.thumb
	.thumb_func
	.type func_080346C0, %function
func_080346C0: @ 080346C0
	push {r4, lr}
	adds r2, r0, #0x0
	ldr r0, _080346F0 @ =0x02039BA0
	ldr r0, [r0, #0x00]
	adds r3, r0, #0x0
	adds r3, #0x18
	adds r0, r2, #0x0
	adds r0, #0x66
	ldrh r0, [r0, #0x00]
	movs r4, #0x01
	adds r1, r4, #0x0
	ands r1, r0
	cmp r1, #0x00
	beq _080346F4
	ldr r0, [r3, #0x0C]
	ldr r1, [r2, #0x78]
	cmp r0, r1
	bge _080346E6
	adds r1, r0, #0x0
_080346E6:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r4, [r0, #0x00]
	b _080346FC
	.byte 0x00, 0x00
_080346F0: .4byte 0x02039BA0
_080346F4:
	adds r0, r2, #0x0
	adds r0, #0xBC
	strb r1, [r0, #0x00]
	ldr r1, [r3, #0x0C]
_080346FC:
	adds r0, r1, #0x0
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
