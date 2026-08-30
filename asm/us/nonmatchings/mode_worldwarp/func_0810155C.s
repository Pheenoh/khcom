.syntax unified
	.align 2, 0
	.global func_0810155C
	.thumb
	.thumb_func
	.type func_0810155C, %function
func_0810155C: @ 0810155C
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_08101518
	adds r4, r4, r0
	ldr r0, _08101578 @ =0x0001869F
	cmp r4, r0
	bhi _0810157C
	adds r0, r4, #0x0
	bl func_08101528
	movs r0, #0x01
	b _08101582
	.byte 0x00, 0x00
_08101578: .4byte 0x0001869F
_0810157C:
	bl func_08101528
	movs r0, #0x00
_08101582:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
