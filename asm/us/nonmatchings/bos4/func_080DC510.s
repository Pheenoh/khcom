.syntax unified
	.align 2, 0
	.global func_080DC510
	.thumb
	.thumb_func
	.type func_080DC510, %function
func_080DC510: @ 080DC510
	ldr r0, _080DC524 @ =0x02034F0C
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x58]
	ldr r2, [r0, #0x5C]
	movs r0, #0x04
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
	.byte 0x00, 0x00
_080DC524: .4byte 0x02034F0C
.syntax divided
