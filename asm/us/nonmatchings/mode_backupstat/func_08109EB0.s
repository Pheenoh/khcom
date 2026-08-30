.syntax unified
	.align 2, 0
	.global func_08109EB0
	.thumb
	.thumb_func
	.type func_08109EB0, %function
func_08109EB0: @ 08109EB0
	ldr r2, [r0, #0x2C]
	cmp r2, #0x00
	beq _08109EC4
	movs r3, #0x32
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r2, r0
	b _08109EC6
_08109EC4:
	ldr r0, _08109EC8 @ =0x09A4AF34
_08109EC6:
	bx lr
_08109EC8: .4byte 0x09A4AF34
.syntax divided
