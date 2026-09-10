.syntax unified
	.align 2, 0
	.arm
	.global func_08109AAC
	.type func_08109AAC, %function
func_08109AAC:
	mov	ip, sp
	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr, pc}
	sub	fp, ip, #4
	bl	.LForwardTransform
	mov	ip, r1
	ldm	ip, {r3, r4, r5, r6, r7, r8, r9, sl}
	mov	r0, r3
	mov	r1, #8
	bl	.LQuantize
	bl	.LDequantize
	rsb	r3, r0, r3, lsl #1
	mov	r0, r4
	bl	.LQuantize
	bl	.LDequantize
	rsb	r4, r0, r4, lsl #1
	mov	r0, r5
	mov	r1, #9
	bl	.LQuantize
	bl	.LDequantize
	rsb	r5, r0, r5, lsl #1
	mov	r0, r6
	bl	.LQuantize
	bl	.LDequantize
	rsb	r6, r0, r6, lsl #1
	mov	r0, r7
	mov	r1, #10
	bl	.LQuantize
	bl	.LDequantize
	rsb	r7, r0, r7, lsl #1
	mov	r0, r8
	mov	r1, #11
	bl	.LQuantize
	bl	.LDequantize
	rsb	r8, r0, r8, lsl #1
	mov	r0, r9
	mov	r1, #12
	bl	.LQuantize
	bl	.LDequantize
	rsb	r9, r0, r9, lsl #1
	mov	r0, sl
	mov	r1, #13
	bl	.LQuantize
	bl	.LDequantize
	rsb	sl, r0, sl, lsl #1
	mov	r0, r3
	mov	r1, #8
	bl	.LQuantize
	mov	r3, r0
	mov	r0, r4
	bl	.LQuantize
	mov	r4, r0
	mov	r0, r5
	mov	r1, #9
	bl	.LQuantize
	mov	r5, r0
	mov	r0, r6
	bl	.LQuantize
	mov	r6, r0
	mov	r0, r7
	mov	r1, #10
	bl	.LQuantize
	mov	r7, r0
	mov	r0, r8
	mov	r1, #11
	bl	.LQuantize
	mov	r8, r0
	mov	r0, r9
	mov	r1, #12
	bl	.LQuantize
	mov	r9, r0
	mov	r0, sl
	mov	r1, #13
	bl	.LQuantize
	mov	sl, r0
	stm	ip, {r3, r4, r5, r6, r7, r8, r9, sl}
	ldmdb	fp, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, sp, lr}
	bx	lr
.LInverseShifted:
	mov	ip, sp
	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr, pc}
	sub	fp, ip, #4
	mov	ip, r1
	ldm	r2!, {r3, r4, r5, r6}
	ldm	r0!, {r7, r8, r9, sl}
	lsl	r7, r7, r3
	lsl	r8, r8, r4
	lsl	r9, r9, r5
	lsl	sl, sl, r6
	stmia	r1!, {r7, r8, r9, sl}
	ldm	r2!, {r3, r4, r5, r6}
	ldm	r0!, {r7, r8, r9, sl}
	lsl	r7, r7, r3
	lsl	r8, r8, r4
	lsl	r9, r9, r5
	lsl	sl, sl, r6
	stmia	r1!, {r7, r8, r9, sl}
	mov	r0, ip
	mov	r1, ip
	bl	.LInverseTransform
	mov	r0, ip
	add	r1, ip, #32
.LShiftedDivide:
	ldr	r2, [r0]
	cmp	r2, #0
	asrgt	r2, r2, #2
	rsble	r2, r2, #0
	asrle	r2, r2, #2
	rsble	r2, r2, #0
	str	r2, [r0], #4
	cmp	r0, r1
	blt	.LShiftedDivide
	ldmdb	fp, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, sp, lr}
	bx	lr
.LInverseSquared:
	mov	ip, sp
	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr, pc}
	sub	fp, ip, #4
	mov	ip, r1
	ldm	r0, {r3, r4, r5, r6, r7, r8, r9, sl}
	mov	r0, r3
	mov	r1, #8
	bl	.LDequantize
	mov	r3, r0
	mov	r0, r4
	bl	.LDequantize
	mov	r4, r0
	mov	r0, r5
	mov	r1, #9
	bl	.LDequantize
	mov	r5, r0
	mov	r0, r6
	bl	.LDequantize
	mov	r6, r0
	mov	r0, r7
	mov	r1, #10
	bl	.LDequantize
	mov	r7, r0
	mov	r0, r8
	mov	r1, #11
	bl	.LDequantize
	mov	r8, r0
	mov	r0, r9
	mov	r1, #12
	bl	.LDequantize
	mov	r9, r0
	mov	r0, sl
	mov	r1, #13
	bl	.LDequantize
	mov	sl, r0
	stm	ip, {r3, r4, r5, r6, r7, r8, r9, sl}
	mov	r0, ip
	mov	r1, ip
	bl	.LInverseTransform
	mov	r0, ip
	add	r1, ip, #32
.LSquaredDivide:
	ldr	r2, [r0]
	cmp	r2, #0
	asrgt	r2, r2, #2
	rsble	r2, r2, #0
	asrle	r2, r2, #2
	rsble	r2, r2, #0
	str	r2, [r0], #4
	cmp	r0, r1
	blt	.LSquaredDivide
	ldmdb	fp, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, sp, lr}
	bx	lr
.LQuantize:
	cmp	r0, #0
	rsble	r0, r0, #0
	asr	r0, r0, r1
	ldr r2, .LSqrtTable
	ldrb	r0, [r2, r0]
	rsble	r0, r0, #0
	mov	pc, lr
.LSqrtTable:
	.4byte 0x09c43708
.LDequantize:
	cmp	r0, #0
	mul	r2, r0, r0
	lsl	r0, r2, r1
	rsble	r0, r0, #0
	mov	pc, lr
.LForwardTransform:
	push	{r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	ldm	r0, {r2, r3, r4, r5, r6, r7, r8, r9}
	add	sl, r2, r9
	add	lr, r5, r6
	add	fp, r3, r8
	add	ip, r4, r7
	add	r2, sl, lr
	rsb	r5, lr, sl
	add	r3, fp, ip
	rsb	r4, ip, fp
	add	r2, r2, r3
	rsb	r3, r3, r2, asr #1
	add	r6, r5, r5, lsl #1
	sub	r4, r4, r6, asr #3
	add	r6, r4, r4, lsl #1
	add	r5, r5, r6, asr #3
	str	r2, [r1]
	str	r3, [r1, #16]
	str	r5, [r1, #8]
	str	r4, [r1, #24]
	ldm	r0, {r2, r3, r4, r5, r6, r7, r8, r9}
	rsb	sl, r6, r5
	rsb	fp, r7, r4
	rsb	ip, r8, r3
	rsb	lr, r9, r2
	add	r2, fp, fp, lsl #1
	add	ip, ip, r2, asr #3
	add	r2, ip, ip, lsl #2
	rsb	fp, fp, r2, asr #3
	add	r2, sl, fp
	rsb	r3, fp, sl
	rsb	r4, ip, lr
	add	r5, lr, ip
	sub	r2, r2, r5, asr #3
	rsb	r6, r4, r4, lsl #3
	add	r3, r3, r6, asr #3
	sub	r4, r4, r3, asr #1
	str	r5, [r1, #4]
	str	r4, [r1, #12]
	str	r3, [r1, #20]
	str	r2, [r1, #28]
	pop	{r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	bx	lr
.LInverseTransform:
	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	ldm	r0, {r2, r3, r4, r5, r6, r7, r8, r9}
	add	r5, r5, r7, asr #1
	rsb	sl, r5, r5, lsl #3
	sub	r7, r7, sl, asr #3
	add	r9, r9, r3, asr #3
	add	sl, r9, r7
	rsb	fp, r7, r9
	rsb	ip, r5, r3
	add	lr, r3, r5
	add	r3, ip, ip, lsl #2
	rsb	fp, fp, r3, asr #3
	add	r3, fp, fp, lsl #1
	sub	ip, ip, r3, asr #3
	add	r3, r8, r8, lsl #1
	sub	r4, r4, r3, asr #3
	add	r3, r4, r4, lsl #1
	add	r8, r8, r3, asr #3
	rsb	r6, r6, r2, asr #1
	sub	r2, r2, r6
	add	r3, r2, r4
	add	r5, r6, r8
	rsb	r7, r8, r6
	rsb	r9, r4, r2
	add	r2, r3, lr
	add	r4, r5, ip
	add	r6, r7, fp
	add	r8, r9, sl
	stmia	r1!, {r2, r4, r6, r8}
	rsb	r2, sl, r9
	rsb	r4, fp, r7
	rsb	r6, ip, r5
	rsb	r8, lr, r3
	stm	r1, {r2, r4, r6, r8}
	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
	mov	pc, lr
	.size func_08109AAC, . - func_08109AAC
	.thumb
.syntax divided
