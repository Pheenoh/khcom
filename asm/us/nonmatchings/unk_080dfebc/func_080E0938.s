.syntax unified
	.align 2, 0
	.global func_080E0938
	.thumb
	.thumb_func
	.type func_080E0938, %function
func_080E0938: @ 080E0938
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	ldr r0, _080E095C @ =0x0984D32C
	adds r4, r4, r0
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #0x03]
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
_080E095C: .4byte 0x0984D32C
.syntax divided
