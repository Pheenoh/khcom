.syntax unified
	.align 2, 0
	.global func_080C7684
	.thumb
	.thumb_func
	.type func_080C7684, %function
func_080C7684: @ 080C7684
	push {r4, lr}
	ldr r4, _080C76A0 @ =0x0203C3D8
	movs r3, #0x01
	strb r3, [r4, #0x00]
	ldr r3, _080C76A4 @ =0x02034D9C
	str r0, [r3, #0x00]
	ldr r0, _080C76A8 @ =0x02034DA0
	lsls r1, r1, #0x01
	str r1, [r0, #0x00]
	ldr r0, _080C76AC @ =0x02034DA4
	str r2, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080C76A0: .4byte 0x0203C3D8
_080C76A4: .4byte 0x02034D9C
_080C76A8: .4byte 0x02034DA0
_080C76AC: .4byte 0x02034DA4
.syntax divided
