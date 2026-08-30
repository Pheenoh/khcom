.syntax unified
	.align 2, 0
	.global func_08048A68
	.thumb
	.thumb_func
	.type func_08048A68, %function
func_08048A68: @ 08048A68
	push {r4, lr}
	adds r4, r0, #0x0
	adds r4, #0x20
	movs r1, #0xB2
	lsls r1, r1, #0x01
	adds r3, r0, r1
	ldr r2, _08048AA0 @ =0x08121400
	subs r1, #0x16
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	movs r1, #0xFF
	ands r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r2
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r1, r1, #0x04
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	ldr r1, [r4, #0x0C]
	subs r0, r0, r1
	asrs r0, r0, #0x02
	adds r1, r1, r0
	str r1, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
_08048AA0: .4byte 0x08121400
.syntax divided
