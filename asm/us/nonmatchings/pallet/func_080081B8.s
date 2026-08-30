.syntax unified
	.align 2, 0
	.global func_080081B8
	.thumb
	.thumb_func
	.type func_080081B8, %function
func_080081B8: @ 080081B8
	push {r4, lr}
	movs r4, #0x00
	movs r3, #0x01
	ldr r1, _080081E0 @ =0x02039B70
	movs r2, #0x03
_080081C2:
	strb r3, [r1, #0x00]
	strb r3, [r1, #0x01]
	strb r4, [r1, #0x02]
	adds r1, #0x04
	subs r2, #0x01
	cmp r2, #0x00
	bge _080081C2
	bl func_08006C84
	bl func_080002D4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080081E0: .4byte 0x02039B70
.syntax divided
