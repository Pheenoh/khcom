.syntax unified
	.align 2, 0
	.global func_080C5D24
	.thumb
	.thumb_func
	.type func_080C5D24, %function
func_080C5D24: @ 080C5D24
	push {r4, lr}
	movs r1, #0x00
	ldr r4, _080C5D4C @ =0x02039810
	movs r3, #0x00
_080C5D2C:
	lsls r0, r1, #0x02
	adds r2, r1, #0x1
	movs r1, #0x01
	adds r0, r0, r4
	adds r0, #0x02
_080C5D36:
	strh r3, [r0, #0x00]
	subs r0, #0x02
	subs r1, #0x01
	cmp r1, #0x00
	bge _080C5D36
	adds r1, r2, #0x0
	cmp r1, #0x03
	ble _080C5D2C
	pop {r4}
	pop {r0}
	bx r0
_080C5D4C: .4byte 0x02039810
.syntax divided
