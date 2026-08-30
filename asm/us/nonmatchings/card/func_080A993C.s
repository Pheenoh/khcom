.syntax unified
	.align 2, 0
	.global func_080A993C
	.thumb
	.thumb_func
	.type func_080A993C, %function
func_080A993C: @ 080A993C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r2, #0x00
	ldr r5, _080A9950 @ =0x000003B5
	ldr r3, _080A9954 @ =0x08F70AB0
_080A9946:
	ldrh r1, [r3, #0x1C]
	cmp r1, r4
	bne _080A9958
	adds r0, r2, #0x0
	b _080A9960
_080A9950: .4byte 0x000003B5
_080A9954: .4byte 0x08F70AB0
_080A9958:
	adds r3, #0x34
	adds r2, #0x01
	cmp r2, r5
	bls _080A9946
_080A9960:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
