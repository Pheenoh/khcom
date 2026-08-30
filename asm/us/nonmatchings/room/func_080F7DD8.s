.syntax unified
	.align 2, 0
	.global func_080F7DD8
	.thumb
	.thumb_func
	.type func_080F7DD8, %function
func_080F7DD8: @ 080F7DD8
	adds r2, r0, #0x0
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _080F7DE6
	movs r0, #0x20
	b _080F7E06
_080F7DE6:
	movs r1, #0x00
	ldr r3, _080F7E08 @ =0x0999204C
	ldr r0, [r3, #0x00]
	cmp r2, r0
	blt _080F7E04
_080F7DF0:
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3F
	bhi _080F7E04
	lsls r0, r1, #0x02
	adds r0, r0, r3
	ldr r0, [r0, #0x00]
	cmp r2, r0
	bge _080F7DF0
_080F7E04:
	adds r0, r1, #0x0
_080F7E06:
	bx lr
_080F7E08: .4byte 0x0999204C
.syntax divided
