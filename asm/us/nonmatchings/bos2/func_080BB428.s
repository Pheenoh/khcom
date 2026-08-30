.syntax unified
	.align 2, 0
	.global func_080BB428
	.thumb
	.thumb_func
	.type func_080BB428, %function
func_080BB428: @ 080BB428
	adds r2, r0, #0x0
	movs r3, #0x03
_080BB42C:
	ldrb r0, [r1, #0x00]
	strh r0, [r2, #0x14]
	adds r1, #0x04
	adds r2, #0x34
	subs r3, #0x01
	cmp r3, #0x00
	bge _080BB42C
	bx lr
.syntax divided
