.syntax unified
	.align 2, 0
	.global func_080CA9DC
	.thumb
	.thumb_func
	.type func_080CA9DC, %function
func_080CA9DC: @ 080CA9DC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldrb r5, [r4, #0x14]
	bl func_080CA724
	ldrb r0, [r4, #0x14]
	cmp r5, r0
	beq _080CAA0C
	ldrb r1, [r4, #0x14]
	adds r0, r5, #0x0
	bl func_08005824
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bge _080CA9FE
	negs r0, r0
_080CA9FE:
	cmp r0, #0x64
	ble _080CAA06
	movs r0, #0x00
	b _080CAA0A
_080CAA06:
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x01
_080CAA0A:
	str r0, [r4, #0x10]
_080CAA0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
