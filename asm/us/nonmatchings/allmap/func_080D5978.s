.syntax unified
	.align 2, 0
	.global func_080D5978
	.thumb
	.thumb_func
	.type func_080D5978, %function
func_080D5978: @ 080D5978
	push {lr}
	adds r3, r1, #0x0
	lsls r0, r0, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _080D5994 @ =0x02034EC4
	lsrs r0, r0, #0x0B
	ldr r1, [r1, #0x00]
	adds r1, r1, r0
	adds r0, r3, #0x0
	bl func_080043B4
	pop {r0}
	bx r0
_080D5994: .4byte 0x02034EC4
.syntax divided
