.syntax unified
	.align 2, 0
	.global MPlayJumpTableCopy
	.thumb
	.thumb_func
	.type MPlayJumpTableCopy, %function
MPlayJumpTableCopy: @ 0811F5E8
	mov r12, lr
	movs r1, #0x24
	ldr r2, _0811F618 @ =0x09D6D348
_0811F5EE:
	ldr r3, [r2, #0x00]
	bl func_0811F602
	stm r0!, {r3}
	adds r2, #0x04
	subs r1, #0x01
	bgt _0811F5EE
	bx r12
	.byte 0x00, 0x00, 0x13, 0x78
.syntax divided
