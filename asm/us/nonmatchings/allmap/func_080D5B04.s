.syntax unified
	.align 2, 0
	.global func_080D5B04
	.thumb
	.thumb_func
	.type func_080D5B04, %function
func_080D5B04: @ 080D5B04
	push {lr}
	ldr r1, _080D5B2C @ =0x0983F398
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	movs r0, #0x00
	movs r1, #0x05
	movs r2, #0x10
	bl func_080057A0
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x06
	bl m4aSongNumStart
	pop {r0}
	bx r0
_080D5B2C: .4byte 0x0983F398
.syntax divided
